#pragma once

#include <iostream>
#include <stdio.h>

enum{
    UNKNOWN,// <0.4902,0.4824,0.4784>
    FLOOR,// <0,0,1.0000>
    CEILING,// <0.9137,0.3490,0.1882>
    WALL,// <0,0.8549,0>
    BED,// <0.5843,0,0.9412>
    CHAIR,// <0.8706,0.9451,0.0941>
    FURNITURE,// <1.0000,0.8078,0.8078>
    NIGHTSTAND,// <0,0.8784,0.8980>
    SHELF,// <0.4157,0.5333,0.8000>
    CURTAIN,// <0.4588,0.1137,0.1608>
    PAINTING,// <0.9412,0.1333,0.9216>
    PILLOWS,// <0,0.6549,0.6118>
    DOOR,// <0.9765,0.5451,0>
    WINDOW,// <0.8824,0.8980,0.7608>
    TABLE,// <1.0000,0,0>
    SOFA,// <0.8118,0.7176,0.2706>
    LAMP,// <0.7922,0.5804,0.5804>
    VASE,
    PLANT,
    PLATE,
    STAND
};

int obj_label2training_label(std::string& objectLabel)
{
    std::transform(objectLabel.begin(),
            objectLabel.end(),
            objectLabel.begin(),
            ::tolower);


    if ( ( objectLabel.find("floor") != std::string::npos )
            || objectLabel.find("carpet") != std::string::npos
            || objectLabel.find("ground") != std::string::npos
            || objectLabel.find("rug") != std::string::npos
            || objectLabel.find("mat_") != std::string::npos )
        return FLOOR;

    else if ( objectLabel.find("ceiling") != std::string::npos )
        return CEILING;

    else if ( objectLabel.find("wall") != std::string::npos||
            objectLabel.find("room_skeleton") != std::string::npos)
        return WALL;

    else if (( objectLabel.find("bed") != std::string::npos)
            || ( objectLabel.find("duvet") != std::string::npos)
            || (objectLabel.find("furniture") != std::string::npos )
            )
        return BED;

    else if ( objectLabel.find("chair") != std::string::npos)
        return CHAIR;

    else if ( (objectLabel.find("cupboard") != std::string::npos ) ||
            (objectLabel.find("bench") != std::string::npos ) ||
            //              (objectLabel.find("furniture") != std::string::npos )||
            (objectLabel.find("chest") != std::string::npos ) ||
            (objectLabel.find("drawers") != std::string::npos ) ||
            (objectLabel.find("wardrobe") != std::string::npos ))
        return FURNITURE;

    else if ( (objectLabel.find("nightstand") != std::string::npos ) ||
            (objectLabel.find("night_stand") != std::string::npos ) )
        return NIGHTSTAND;

    else if ( (objectLabel.find("shelf") != std::string::npos ) ||
            (objectLabel.find("shelves") != std::string::npos ) )
        return SHELF;

    else if ( ( objectLabel.find("curtain") != std::string::npos ) ||
            objectLabel.find("blind") != std::string::npos )
        return CURTAIN;

    else if ( (objectLabel.find("painting") != std::string::npos ) ||
            (objectLabel.find("paint") != std::string::npos ) ||
            (objectLabel.find("mirror") != std::string::npos ) ||
            (objectLabel.find("tv") != std::string::npos ) )
        return PAINTING;

    else if ( (objectLabel.find("pillow") != std::string::npos ) ||
            (objectLabel.find("cushion") != std::string::npos ) ||
            (objectLabel.find("pilow") != std::string::npos ) )
        return PILLOWS;

    //    else if ( (objectLabel.find("book") != std::string::npos )  )
    //        return "BOOKS";

    //    else if ( (objectLabel.find("door") != std::string::npos )  )
    //        return DOOR;

    /// Just putting door into windows for now...
    else if ( (objectLabel.find("window") != std::string::npos )
            || (objectLabel.find("door") != std::string::npos ))
        return WINDOW;

    else if ( objectLabel.find("table") != std::string::npos)
        return TABLE;

    else if ( (objectLabel.find("sofa") != std::string::npos ) )
        return SOFA;

    else if ( (objectLabel.find("lamp") != std::string::npos ) )
        return LAMP;

    else if ( (objectLabel.find("palm") != std::string::npos ) )
        return PLANT;

    else if ( (objectLabel.find("vase") != std::string::npos ) )
        return VASE;

    else if ( (objectLabel.find("plate") != std::string::npos ) )
        return PLATE;

    else if ( (objectLabel.find("stand") != std::string::npos ) )
        return STAND;

    else
        return UNKNOWN;

}
