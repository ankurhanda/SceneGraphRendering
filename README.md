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

in your build run 

```
./Examples/TextureRender/TextureRender ../data/bedroom1.obj 
```

The output files are written in the **../data/bedroom1_data** folder
