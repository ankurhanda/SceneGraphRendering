#include <iostream>
#include <chrono>
#include <thread>
#include <Eigen/Eigen>

#include <pangolin/pangolin.h>
#include <pangolin/display.h>
#include <SceneGraph/SceneGraph.h>

using namespace std;
using namespace pangolin;

void Usage() {
    cout << "Usage: ModelViewer filename" << endl;
}

int main( int argc, char* argv[] )
{
    if(argc != 2) {
        Usage();
        exit(-1);
    }

    std::string obj_basename(argv[1]);
    std::size_t find_dot   = obj_basename.find(".obj");
    std::size_t find_slash = obj_basename.find_last_of('/');

    std::cout<<"  find_dot = " << find_dot << std::endl;
    std::cout<<"find_slash = " << find_slash << std::endl;

    obj_basename = obj_basename.substr(find_slash+1,find_dot-find_slash-1);

    std::string data_dir = "../data/" + obj_basename + "_data";

    const std::string model_filename(argv[1]);

    // Create OpenGL window in single line thanks to GLUT
    pangolin::CreateWindowAndBind("Main",640,480);
    SceneGraph::GLSceneGraph::ApplyPreferredGlSettings();
    glClearColor( 0,0,0,0);
    glewInit();



    // Scenegraph to hold GLObjects and relative transformations
    SceneGraph::GLSceneGraph glGraph;

    SceneGraph::GLLight light(10,10,-100);
    glGraph.AddChild(&light);

//    SceneGraph::GLGrid grid(10,1,true);
//    glGraph.AddChild(&grid);

    SceneGraph::AxisAlignedBoundingBox bbox;
    
#ifdef HAVE_ASSIMP
    // Define a mesh object and try to load model
    SceneGraph::GLMesh glMesh;
    try {
        glMesh.Init(model_filename);
        glGraph.AddChild(&glMesh);
        bbox = glMesh.ObjectAndChildrenBounds();
    }catch(exception e) {
        cerr << "Cannot load mesh." << endl;
        cerr << e.what() << std::endl;
        exit(-1);
    }
#endif // HAVE_ASSIMP

    
    const Eigen::Vector3d center = bbox.Center();
    double size = bbox.Size().norm();
   
    // Define Camera Render Object (for view / scene browsing)
    pangolin::OpenGlRenderState stacks3d(
        pangolin::ProjectionMatrixRDF_BottomLeft(640,480,420,420,320,240, 0.01, 1000),
        pangolin::ModelViewLookAt(center(0), center(1) + size, center(2) + size/4,
                                  center(0), center(1), center(2), pangolin::AxisNegZ)
    );

    int UI_WIDTH = 150;

    /// Create a Panel
    pangolin::View& d_panel = pangolin::CreatePanel("ui")
            .SetBounds(1.0, 0.0, 0, pangolin::Attach::Pix(UI_WIDTH));

    /// Add named OpenGL viewport to window and provide 3D Handler
    pangolin::View& d_cam = pangolin::Display("cam")
      .SetBounds(0.0, 1, Attach::Pix(UI_WIDTH), 1, -640.0f/480.0f)
      .SetHandler(new Handler3D(stacks3d));

    // We define a new view which will reside within the container.
//    pangolin::View view3d;

    // We set the views location on screen and add a handler which will
    // let user input update the model_view matrix (stacks3d) and feed through
    // to our scenegraph
//    view3d.SetBounds(0.0, 1.0, 0.0, 1.0, -640.0f/480.0f)
//          .SetHandler(new SceneGraph::HandlerSceneGraph(glGraph,stacks3d))
//          .SetDrawFunction(SceneGraph::ActivateDrawFunctor(glGraph, stacks3d));

    // Add our views as children to the base container.
//    pangolin::DisplayBase().AddDisplay(view3d);


        OpenGlMatrix openglSE3Matrix;


    // Default hooks for exiting (Esc) and fullscreen (tab).
    while( !pangolin::ShouldQuit() )
    {
        // Clear whole screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        d_cam.ActivateAndScissor();
        d_cam.ActivateScissorAndClear(stacks3d);


        glMesh.DrawCanonicalObject();

        // Swap frames and Process Events
        pangolin::FinishFrame();

        // Pause for 1/60th of a second.
//        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 60));
    }

    return 0;
}
