class Solution {
    public int largestRectangleArea(int[] h) {
        int n = h.length;
        int maxArea = Integer.MIN_VALUE;
        Stack<Integer> st = new Stack<>();

        for(int i=0 ; i<=n ; i++){
          while(!st.isEmpty() &&(i==n || h[st.peek()] >= h[i])){
            int height = h[st.peek()];
            st.pop();
            int width;
            if(st.isEmpty()) width = i;
            else width = i - st.peek() - 1;
            maxArea = Math.max(maxArea , height * width);
          }
             st.push(i);
        }
       
        return maxArea;
    }
}