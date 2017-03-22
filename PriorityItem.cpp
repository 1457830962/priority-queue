//priorityItem class is used by priorityQueue class. priorityQueue deals with a collection of objects of this class.
template<class T>
class priorityItem {
private:
     T data;
     //priority from 1-5. 1 is highest and 5 is lowest.
     int priority;
public:
     priorityItem() {
          priority = 5;
     }
     priorityItem(T data, int priority) {
          this->data = data;
          this->priority = priority;
     }
     void setData(T data) {
          this->data = data;
     }
     void setPriority(int priority) {
          this->priority = priority;
     }
     T getData() {
          return data;
     }
     int getPriority() {
          return priority;
     }
};