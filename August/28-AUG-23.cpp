class MyStack {
  queue<int> q1,q2;
  int q_num;
public:
    MyStack() {
        q_num=1;
    }
    
    void push(int x) {
        if(q_num==1) 
          q1.push(x);
        else 
          q2.push(x);
    }
    
    int pop() {
        int ret=-1;
        if(q_num==1) {
          q_num=2;

          // fill q2
          while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
          }

          ret=q1.front();
          q1.pop();
        }
        else {
          q_num=1;

          //fill q1
          while(q2.size()>1) {
            q1.push(q2.front());
            q2.pop();
          }

          ret=q2.front();;
          q2.pop();
        }

        return ret;
    }
    
    int top() {
        int ret=-1;
        if(q_num==1) {
          q_num=2;

          // fill q2
          while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
          }

          ret=q1.front();
          q2.push(ret);
          q1.pop();
        }
        else {
          q_num=1;

          //fill q1
          while(q2.size()>1) {
            q1.push(q2.front());
            q2.pop();
          }

          ret=q2.front();
          q1.push(ret);
          q2.pop();
        }

        return ret;
    }
    
    bool empty() {
        if(q_num==1) return q1.empty();
        return q2.empty();
    }
};