/*main.cpp*/

//
// Netflix movie review analysis.
//
// << YOUR NAME >>
// U. of Illinois, Chicago
// CS 341: Fall 2018
// Project 02
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <chrono>

using namespace std;
class Movie{
    int     ID;
    string  Name;
    int     PubYear;
    int     NumReviews;
    double  SumRatings;
    double  AvgRating;

public:
    //
    // constructor:
    //
    Movie(int id, string name, int pubyear)
            : ID(id), Name(name), PubYear(pubyear)
    {
        NumReviews = 0;
        SumRatings = 0.0;
        AvgRating = 0.0;
    }
    string getMovieName() const
    {
        return Name;
    }

};

vector<Movie> InputMovies(string filename)
{
    ifstream file(filename);
    vector<Movie> movies;
    string line;



    getline(file, line);  // discard first line (column headers):

    while (getline(file, line))
    {
        stringstream  ss(line);

        // format: MovieID,MovieName,PubYear
        string movieID, name, year;

        getline(ss, movieID, ',');
        getline(ss, name, ',');
        getline(ss, year);

        Movie m(stoi(movieID), name, stoi(year));

        movies.push_back(m);
    }

    //
    // done, return input:
    //
    return movies;
}
int main()
{
    cout << "** Netflix Movie Review Analysis **" << endl;
    cout << endl;

    //
    // input the filenames to process
    //

    string moviesFN, reviewsFN, line, line2;


    cin >> moviesFN;
    cin >> reviewsFN;
    ifstream file(moviesFN);
    ifstream file2(reviewsFN);

    cout << moviesFN << endl;
    cout << reviewsFN << endl;
    cout << endl;
    auto  beginTime  =  std::chrono::steady_clock::now();
    vector<Movie> movies = InputMovies(moviesFN);
    auto  endTime  =  std::chrono::steady_clock::now();
    auto diff  =  endTime-beginTime;
    cout  <<  "  [  time:  "
            <<  std::chrono::duration<double,  std::milli>(diff).count()
            <<  "  ms  ]"  <<  endl;
    for (int i = 0; i < movies.size(); ++i)
    {
        if(i == 0){
            cout << "Reading Movies ..." << movies.size() << endl;
        }
        cout << movies[i].getMovieName() << endl;

    }

    //
    // TODO:
    //


    //
    // done:
    //
    cout << "** DONE! **" << endl << endl;

    return 0;
}