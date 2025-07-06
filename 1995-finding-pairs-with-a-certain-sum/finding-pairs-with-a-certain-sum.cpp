class FindSumPairs 
{
    vector<int> nums1;
    vector<int> nums2;
    vector<int> freqArr;
    unordered_map<int, int> extraMap;
    const int M = 200000;

public:
    // Constructor: FindSumPairs(nums1, nums2)
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        // Step 1: Save arrays
        this->nums1 = nums1;
        this->nums2 = nums2;

        // Step 2: Initialize frequency structures
        freqArr = vector<int>(M + 1, 0);

        // Step 3: Fill frequency data from nums2
        for (int v : nums2) 
        {
            if (v <= M) 
            {
                freqArr[v]++;
            } 
            else 
            {
                extraMap[v]++;
            }
        }
    }

    void add(int index, int val) 
    {
        // Step 1: Get old value
        int old = nums2[index];

        // Step 2: Decrease count of old value
        if (old <= M) 
        {
            freqArr[old]--;
        } 
        else 
        {
            if (--extraMap[old] == 0)
            {
                extraMap.erase(old);
            }
        }

        // Step 3: Compute new value
        int nw = old + val;
        
        // Step 4: Update value
        nums2[index] = nw; 

        // Step 5: Increase count of new value
        if (nw <= M) 
        {
            freqArr[nw]++;
        } 
        else 
        {
            extraMap[nw]++;
        }
    }

    int count(int tot) 
    {
        // Step 1: Initialize answer
        int ans = 0;

        // Step 2: Loop through nums1
        for (int a : nums1) 
        { 
            // Step 3: Compute b
            int b = tot - a;  

            // Step 4: Lookup b in frequency structures
            if (b >= 0 && b <= M) 
            {
                ans += freqArr[b];
            } 
            else 
            {
                ans += extraMap[b];
            }
        }

        // Step 5: Return answer
        return ans;
    }
};