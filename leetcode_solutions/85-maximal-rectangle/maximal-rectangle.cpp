class Solution {
public:

     int maxAreaRectangle(vector<int>height)
     {
        int maxArea=0;
        stack<int>st;
        int n=height.size();
        for(int i=0;i<=n;i++)
        {
            int curr=i==n?0:height[i];
         while(!st.empty() && curr < height[st.top()])//stack stores in strictly increasing order 
            {
                int h=height[st.top()];
                st.pop();
                int w=st.empty()?i:i-st.top()-1;//right-left-1 widht exclusive
                maxArea=max(maxArea,h*w);
            }
            st.push(i);
            
        }
        return maxArea;
     }

             
    int maximalRectangle(vector<vector<char>>& matrix) {
        //please do lc 84 before this ..t Create a 1D heights array of size equal to the number of columns, initialized to 0.Loop through the 2D matrix row by row.
       /* For each row, update the heights array:If matrix[row][col] == '1', increment the height: heights[col] += 1.If matrix[row][col] == '0', the chain breaks, so reset the height: heights[col] = 0.
        After updating the histogram for the current row, pass the heights array into your existing largestRectangleArea function to find the maximum area possible up to that row.
        Keep track of the global maximum area across all rows*/
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>height(cols,0);
        int area=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]=='1')
                height[j]+=1;
                else
                height[j]=0;
            }
              area= max(area,maxAreaRectangle(height));
        }
      
        return area;
        
    }
};