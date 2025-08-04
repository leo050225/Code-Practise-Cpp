class Solution {
public:

    int getSum(int n){
        int sum = 0;

        while(n){
            sum+=(n%10)*(n%10);
            n/=10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> num_set;

        while (true){
            int num = getSum(n);

            if(num == 1)return true;

            if(num_set.find(num)!=num_set.end()){
                return false;
            }
            else{
                num_set.insert(num);
            }
            n = num;
        }
        
    }
};
