static void count_sort(const vector<int>& a, int byte, vector<int> &out) {
        const int shift = 8 * byte;
        
        size_t cts[256] = {};
        for (size_t i = a.size(); i-- > 0;) {
            cts[(static_cast<unsigned>(a[i]) >> shift) & 0xFF] += 1;
        }
        
        for (size_t i = 1; i < 256; ++i) {
            cts[i] += cts[i - 1];
        }
        
        for (size_t i = a.size(); i-- > 0;) {
            out[--cts[(static_cast<unsigned>(a[i]) >> shift) & 0xFF]] = a[i];
        }
    }
    static void split_reverse_neg(const vector<int> &a, vector<int> &out) {
        size_t cts[2] = {};
        for (size_t i = a.size(); i-- > 0;) {
            cts[a[i] < 0 ? 0 : 1] += 1;
        }
        const size_t negs = cts[0];
        cts[1] += cts[0];
        
        for (size_t i = a.size(); i-- > 0;) {
            out[--cts[a[i] < 0 ? 0 : 1]] = a[i];
        }
    }
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> tmp(nums.size());
        
        count_sort(nums, 0, tmp);
        count_sort(tmp, 1, nums);
        count_sort(nums, 2, tmp);
        count_sort(tmp, 3, nums);
        split_reverse_neg(nums, tmp);
        nums.swap(tmp);
        
        size_t max_len = 1;
        for (size_t i = 1, n = nums.size(), len = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++len;
                if (len > max_len) {
                    max_len = len;
                }
            } else if (nums[i] != nums[i - 1]) {
                len = 1;
            }
        }
        
        return max_len;
    }
