
//uva11917
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int caseNum, listNum, useDay, limitDay;
    string useCourse, limitCourse;
    map<string, int> myList;

    // get case number
    cin >> caseNum;
    for(int i = 0; i < caseNum; i++) {
        // initialize
        myList.clear();

        // get number of schedule
        cin >> listNum;
        for(int j = 0; j < listNum; j++) {
            // get schedule
            cin >> useCourse >> useDay;

            // put into map
            myList[useCourse] = useDay;
        }

        // get limit day and course
        cin >> limitDay >> limitCourse;

        // output
        cout << "Case " << i + 1 << ": ";
        if(myList.find(limitCourse) == myList.end()) {
            // the course is not in the schedule
            cout << "Do your own homework!" << endl;
        }
        else if(myList[limitCourse] <= limitDay) {
            // finished on the limit day
            cout << "Yesss" << endl;
        }
        else if(myList[limitCourse] <= (limitDay + 5)) {
            // finished over than limit day but not over than 5 days
            cout << "Late" << endl;
        }
        else {
            // finished over than limit day + 5
            cout << "Do your own homework!" << endl;
        }
    }

    return 0;
}
