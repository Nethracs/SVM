/** This project was done as part of computer vision coursework under prof. David crandall
 * svm_multiclass by cornell is used for image classification 
 * https://www.cs.cornell.edu/people/tj/svm_light/svm_multiclass.html
 **/



#include "CImg.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <vector>
#include <Sift.h>
#include <sys/types.h>
#include <dirent.h>
#include <map>
#include <numeric>

//Use the cimg namespace to access the functions easily
using namespace cimg_library;
using namespace std;

// Dataset data structure, set up so that e.g. dataset["bagel"][3] is
// filename of 4th bagel image in the dataset
typedef map<string, vector<string> > Dataset;


#include <svm.h>

// Figure out a list of files in a given directory.
//
vector<string> files_in_directory(const string &directory, bool prepend_directory = false)
{
  vector<string> file_list;
  DIR *dir = opendir(directory.c_str());
  if(!dir)
    throw std::string("Can't find directory " + directory);
  
  struct dirent *dirent;
  while ((dirent = readdir(dir))) 
    if(dirent->d_name[0] != '.')
      file_list.push_back((prepend_directory?(directory+"/"):"")+dirent->d_name);

  closedir(dir);
  return file_list;
}


int main(int argc, char **argv)
{
  try {
    if(argc < 3)
      throw string("Insufficent number of arguments");

    string mode = argv[1];
    string algo = argv[2];
    svm *classifier=0;

    // Scan through the "train" or "test" directory (depending on the
    //  mode) and builds a data structure of the image filenames for each class.
    Dataset filenames; 
    vector<string> class_list = files_in_directory(mode);
    for(vector<string>::const_iterator c = class_list.begin(); c != class_list.end(); ++c)
      filenames[*c] = files_in_directory(mode + "/" + *c, true);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if(algo=="svm")
    {
      classifier = new svm(class_list);
      if(mode=="train")
      {
        classifier->svmtrain(filenames);
        system("./svm_multiclass_learn -c 1.0 train.dat model ");
        
      }
      else if(mode=="test")
      {
        
        classifier->svmtest(filenames);
        system("./svm_multiclass_classify test.dat model predictions");
      
      }
    } 
    

  }
  catch(const string &err) 
  {
    cerr << "Error: " << err << endl;
  }
}








