# SVM

This is a sample implementation for using svm-multiclass by cornell for image classification based on the test images.
https://www.cs.cornell.edu/people/tj/svm_light/svm_multiclass.html

# Usage

We intially resize all the images to fixed size so that we have feature vectors of same size for all the images.

##Train

Feature vectors of the image is written int the format as below in the file named train.dat

**class 1:value 2:value 3:value ....**  

call the svm_multiclass as

**system("./svm_multiclass_learn -c 1.0 train.dat model ");**

1.0 is regularization parameter

This will generate a model file which wil be used in the test phase


##Test

Feature vectors of the image is written int the format as below in the file named test.dat

**class 1:value 2:value 3:value ....**  

call the svm_multiclass as

**system("./svm_multiclass_classify test.dat model predictions")**

This will give the ouput predictions




