class MedianFinder {
    priority_queue<double>s;
    priority_queue<double,vector<double>,greater<double>>g;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // cout<<g.size()<<' '<<s.size()<<endl;
        if(g.size()==0){
            g.push(num);
        }else{
            if(num>g.top()){
                s.push(g.top());
                g.pop();
                g.push(num);
            }else{
                s.push(num);
            }
        }
        // cout<<g.size()<<' '<<s.size()<<endl;
        if((int)g.size()-(int)s.size()==2){
            s.push(g.top());
            g.pop();
        }else if((int)g.size()-(int)s.size()==-1){
            g.push(s.top());
            s.pop();
        }
        // cout<<g.size()<<' '<<s.size()<<endl;
    }
    
    double findMedian() {
        // cout<<"med->"<<g.size()<<' '<<s.size()<<endl;
        if(g.size()==s.size()){
            // cout<<"svhd"<<endl;
            return (g.top()+s.top())/(double)2;
        }else{
            return g.top();
        }
    }
};
