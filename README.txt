Hi there. Hope you having a good day.

The core program can be compiled with make.
The Test cases can be compiled with make test.
The Test cases can be run with make runTest. (Because my tests have literally millions of assertions, it might take some time for the all the tests to run, this is normal so please don't think it's broken, thank you)

main.cpp : where agruments from the terminal are dealt with.
Image.h : where the Image and iterator classes are declared along with all their Accompanying variables, constructors, operators and methods.
Image.cpp : where constructors, methods and operators in the image and iterator classes are defined.

Images need to be the same size for certain operators to work so I have just used the same image for input in the examples below.

The program can be run the following ways (examples):

./imageops -a shrek_rectangular.pgm shrek_rectangular.pgm OutputA.pgm  <- [addition of two images (+ operator)]

./imageops -s shrek_rectangular.pgm shrek_rectangular.pgm OutputS.pgm  <- [substraction of two images (- operator)]

./imageops -i shrek_rectangular.pgm OutputI.pgm  <- [Invert image (! operator)]

./imageops -l shrek_rectangular.pgm donkey_mask.pgm OutputM.pgm <- [Masking of image (/ operator)]

Note you will be prompted to give an integer threshold value after typing in the command below.
./imageops -t shrek_rectangular.pgm OutputT.pgm <- [Threshold of image (* operator)]
