#include "triangulation.h"
#include <cstdio>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <chrono>

using namespace std;

// for string delimiter
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back(s.substr (pos_start));
    return res;
}


int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();

    ////////////////////////////////////////////////////////////////////
    // MAIN PROGRAM:
  
    /* x0, y0, x1, y1, ... */
    std::vector<double> coords;
  
    string delimiter = ",";
    string end = "\n";
    std::ifstream file("Points2D.txt");
        std::string str; 
        while (std::getline(file, str))
        {
          vector<string> v = split (str, delimiter);
          for (int i = 0; i <= 1; ++i)
          {
            double d = atof( v[i].c_str());
            coords.push_back ( d);
            // std::cout << d << std::endl; 
          } 
        };
    
    //triangulation happens here
    delaunator::Delaunator d(coords);

    //open file for writing
    std::ofstream fw("triangles.txt", std::ofstream::out);
    if (fw.is_open())
    {
      //store array contents to text file
      // fw  << "// Format: x1 , y1 , x2 , y2 , x3 , y3 " << "\n";
      for(std::size_t i = 0; i < d.triangles.size(); i+=3) {
        fw  << d.coords[2 * d.triangles[i]] << ","
            << d.coords[2 * d.triangles[i] + 1] << "," 
            << d.coords[2 * d.triangles[i + 1]] << "," 
            << d.coords[2 * d.triangles[i + 1] + 1] << "," 
            << d.coords[2 * d.triangles[i + 2]] << "," 
            << d.coords[2 * d.triangles[i + 2] + 1] << "," 
            << "\n";
      }
      fw.close();
    }


    ////////////////////////////////////////////////////////////////////

    auto t2 = high_resolution_clock::now();
    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
}