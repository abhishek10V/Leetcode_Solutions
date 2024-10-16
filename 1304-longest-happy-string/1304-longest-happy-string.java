class Solution {
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder ans = new StringBuilder();
        PriorityQueue<int[]> pq = new PriorityQueue<>((x , y) -> y[0] - x[0]);

        if(a > 0) pq.offer(new int[]{a , 'a'});
        if(b > 0) pq.offer(new int[]{b , 'b'});
        if(c > 0) pq.offer(new int[]{c , 'c'});


        while(!pq.isEmpty()){
            int[] curr = pq.poll();
            int currCount = curr[0];
            char currChar = (char)curr[1];

            if(ans.length() >= 2 && ans.charAt(ans.length() - 1) == currChar && ans.charAt(ans.length() - 2) == currChar){
                 if(pq.isEmpty()) break;
                 else{
                    int[] next = pq.poll();
                    int nextCount = next[0];
                    char nextChar = (char) next[1];

                    ans.append(nextChar);
                    nextCount--;

                    if(nextCount > 0) pq.offer(new int[]{nextCount , nextChar});

                    pq.offer(curr);
                 }
            }else{
                ans.append(currChar);
                currCount--;

                if(currCount > 0) pq.offer(new int[]{currCount , currChar});
            }
        }
       return ans.toString(); 
    }
}