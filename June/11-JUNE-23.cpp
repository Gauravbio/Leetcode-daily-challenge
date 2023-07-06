class SnapshotArray {
public:
    // vector<int> arr;
    unordered_map<int,map<int,int>> snapshot;
    // vector<vector<int>> snapshot;
    
    int snap_id;

    SnapshotArray(int length) {
        for(int i=0;i<length;i++) {
            map<int,int> m;
            m[0]=0;
            snapshot[i]=m;
        }
        snap_id=0;
    }
    
    void set(int index, int val) {
        // arr[index]=val;
        snapshot[index][snap_id]=val;
    }
    
    int snap() {
        // snapshot.push_back(arr);
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto snapValue=snapshot[index].upper_bound(snap_id);
        snapValue--;
        return snapValue->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */