class Solution {
    public int largestRectangleArea(int[] h) {
        int n = h.length;
        int[] left = new int[n];
        int[] right = new int[n];

        Stack<Integer> st = new Stack<>();

        for(int i=0 ; i<n ; i++){
          while(!st.isEmpty() && h[st.peek()] >= h[i]){
             st.pop();
          }
          if(st.empty()) left[i] = 0;
          else left[i] = st.peek() + 1;
          st.push(i);
        }
        st.clear();
        for(int i=n-1 ; i>=0 ; i--){
          while(!st.isEmpty() && h[st.peek()] >= h[i]){
             st.pop();
          }
          if(st.empty()) right[i] = n-1;
          else right[i] = st.peek() - 1;
          st.push(i);
        }
        int maxArea = Integer.MIN_VALUE;
        for(int i=0 ; i<n ; i++){
            maxArea  = Math.max(maxArea , (right[i] - left[i] + 1) * h[i]);
        }

        return maxArea;
    }
}