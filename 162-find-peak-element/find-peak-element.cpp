const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void* operator new(size_t size) {
    constexpr std::size_t alignment = alignof(std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char* aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;

           if(nums[mid]<=nums[r]) l=mid+1;
           else if(nums[mid]<=nums[l]) r=mid-1;
           else {
              if(nums[mid-1]>nums[mid]) r=mid-1;
              else if (nums[mid+1]>nums[mid]) l=mid+1;
              else return mid; 
           }
        }
        return l;
    }
};