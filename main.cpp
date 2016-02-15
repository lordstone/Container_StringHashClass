class stringHash{
public:

    stringHash(){
        bucketSize = 10;
        db.resize(10);
    }
    stringHash(int mySize){
        if(mySize <= 0) mySize = 1;
        bucketSize = mySize;
        db.resize(mySize);
    }
    int generateKey(string s){
        long long myNum = 0;
        for(int i = 0; i < s.length(); i ++){
            myNum = myNum << 2;
            myNum += (long long) s[i];
        }
        //cout << "myNum:" << myNum << endl;
        return (int) (myNum % (long long)bucketSize);
    }

    void insertStr(string s){
        int key = generateKey(s);
        db[key].push_back(s);
    }

    bool findStr(string s){
        int key = generateKey(s);
        for(auto &i : db[key]){
            if(i == s) return true;
        }
        return false;
    }

    vector<string> outputAll(){
        vector<string> res;
        for(auto &i : db){
            for(auto &j : i){
                res.push_back(j);
            }
        }
        return res;
    }

    void printAll(){
        for(auto &i : db){
            for(auto &j : i){
                cout << j << endl;
            }
        }
    }

    void printAllBuckets(){
        for(int i = 0; i < db.size(); i ++){
                cout << "The " << i << " th bucket has " << db[i].size() << " items:"<< endl;
            for(auto &j : db[i]){
                cout << j << endl;
            }
        }
    }

private:
    vector<vector<string>> db;
    int bucketSize;
};

int main(){
    stringHash mySet (30);
    mySet.insertStr("jiji");
    mySet.insertStr("mimi");
    mySet.insertStr("lili");
    mySet.insertStr("jiweqweqji");
    mySet.insertStr("miasdasdasmi");
    mySet.insertStr("liqweqw1f12rqwfli");
    mySet.insertStr("jijqweqwe1i");
    mySet.insertStr("mi1f12f12mi");
    mySet.insertStr("lilqwfwqqeqwi");
    mySet.insertStr("jiweqwsdasdqeqji");
    mySet.insertStr("miasdasdasqweqweqwmi");
    mySet.insertStr("liqweqw1f12asdqwrqwfli");
    mySet.printAll();

    cout << mySet.findStr("jiji") <<endl;
    cout << mySet.findStr("popip") << endl;
    mySet.printAllBuckets();
    return 0;
}
