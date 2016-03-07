#Dependencies

[Pangolin](https://github.com/ankurhanda/Pangolin-local)

[CVars](https://github.com/arpg/CVars)

[CVD](https://github.com/ankurhanda/libcvd)

#Installation 

mkdir build

cd build

cmake .. && make -j8 

sudo make install

#Rendering RGB-D Video 

After you clone you should see a bedroom scene in the **data** folder under the name  **bedroom1.tgz** and a sample trajectory in the **data/bedroom1_data** folder under the name **bedroom1_trajectory.txt**. To render an RGB-D video follow the steps through

untar bedroom1.tgz in the **data** directory

```
tar -xvzf bedroom1.tgz
```

untar tex_lib.tgz in the **texture_library_samples** directory

```
tar -xvzf tex_lib.tgz
```


in your build run 

```
./Examples/TextureRender/TextureRender ../data/bedroom1.obj 
```

The output files are written in the **../data/bedroom1_data** folder
