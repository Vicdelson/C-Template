//elapsed time
#include <iostream>
#include <ctime> // for time()
#include <unistd.h> // for sleep()

using namespace std;
class Timer {
    public:
    void setStart(time_t ts) {
    start_ts = ts;
    }
    time_t getStart() {
    return start_ts;
    }
    int getElapsedTime() {
    return time(NULL) - getStart();
    }
    private:
    time_t start_ts;
};
int main() {

Timer tmr;
time_t ts;

ts = time(NULL);
tmr.setStart(ts);
sleep(2);

cout << " Start Time: " << tmr.getStart() << endl;
cout << "Elapsed Time: " << tmr.getElapsedTime() << endl;
return 0;
}