class Solution {
public:
    int maxSum(vector<int> arr, int n)
    {
        int max1 = INT_MIN, max_till_now = 0;
        for (int i = 0; i < n; i++)
        {
            max_till_now += arr[i];
            if (max1 < max_till_now)
                max1 = max_till_now;
            if (max_till_now < 0)
                max_till_now = 0;


        }
        return max1;
    }
    int maxSubarraySumCircular(vector<int>& A) {

        int k = maxSum(A, A.size());
        int c = 0;
        for (int i = 0; i < A.size(); i++)
        {
            c += A[i];
            A[i] *= -1;
        }
        int k1 = maxSum(A, A.size());
        c += k1;
        if (c > k && c != 0)
        {
            return c;
        }
        return k;


    }
};