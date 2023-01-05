Input
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
Output
[null, true, false, true]

Explanation
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.

class MyCalendar {
public:
    MyCalendar() {

        
    }
    
    bool book(int start, int end) {
        
    }
};

// The primary challenge in this problem is to find a proper data structure and an efficient algorithm to maintain all valid events, including querying potential conflicting existing events and inserting new valid events.

// In this solution article, we first start with a straightforward idea of brute force to warm up, then one step forward, we improve the naive approach to keep all existing events in sorted order and reduce the time complexity.

class MyCalendar {
private:
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end) {
        for (const auto [s, e] : calendar) {
            if (start < e && s < end) return false;
        }
        calendar.emplace_back(start, end);
        return true;
    }
};

