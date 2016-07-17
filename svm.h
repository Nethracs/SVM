#include<fstream>
using namespace std;
class svm 
{
public:
  svm(const vector<string> &_class_list) {}

  
  // Nearest neighbor training. All this does is read in all the images, resize
  // them to a common size, convert to greyscale, and dump them as vectors to a file
  virtual void svmtrain(const Dataset &filenames) 
  {
    ofstream myfile;
    myfile.open ("train.dat");
    int k=1;
    for(Dataset::const_iterator c_iter=filenames.begin(); c_iter != filenames.end(); ++c_iter)
      {
    	cout << "Processing " << c_iter->first << endl;
    	CImg<double> class_vectors(size*size*3, filenames.size(), 1);
	
    	// convert each image to be a row of this "model" image
    	for(int i=0; i<c_iter->second.size(); i++)
      {
    	  class_vectors = (CImg<double>(c_iter->second[i].c_str())).resize(size,size,1,3).unroll('x'); 
        int ind=1;
        myfile<<k<<" ";
        for(CImg<double>::iterator it=class_vectors.begin()+1;it!=class_vectors.end();it++)
        {
          myfile<<ind<<":"<<*it<<" ";
          ind++;
        }
         myfile<<"\n";
      }


	     k++;
      }
      

  }
  virtual void svmtest(const Dataset &filenames)
  {
    ofstream myfile;
    myfile.open ("test.dat");
    int k=1;
    for(Dataset::const_iterator c_iter=filenames.begin(); c_iter != filenames.end(); ++c_iter)
      {
      cout << "Processing " << c_iter->first << endl;
      CImg<double> class_vectors(size*size*3, filenames.size(), 1);
  
      // convert each image to be a row of this "model" image
      for(int i=0; i<c_iter->second.size(); i++)
      {
        class_vectors = (CImg<double>(c_iter->second[i].c_str())).resize(size,size,1,3).unroll('x');                                 
        int ind=1;
        myfile<<k<<" ";
        for(CImg<double>::iterator it=class_vectors.begin()+1;it!=class_vectors.end();it++)
        {
          myfile<<ind<<":"<<*it<<" ";
          ind++;
        }
         myfile<<"\n";
      }


       k++;
      }  
      
  }

protected:
 

  static const int size=40;  // subsampled image resolution
  map<string, CImg<double> > models; // trained models
  vector<string> class_list;

};
