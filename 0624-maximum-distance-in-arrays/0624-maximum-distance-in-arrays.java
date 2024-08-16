class Solution {
    public int maxDistance(List<List<Integer>> a) {
       int start = a.get(0).get(0);
       int end = a.get(0).get(a.get(0).size() - 1);
       int diff = 0;
       for(int i=1 ; i<a.size(); i++){
          diff = Math.max(diff , Math.max(Math.abs(end - a.get(i).get(0)) , Math.abs(a.get(i).get(a.get(i).size() - 1) - start)));

          start = Math.min(start , a.get(i).get(0));
          end = Math.max(end , a.get(i).get(a.get(i).size() - 1));
       }
        return diff;
    }
}