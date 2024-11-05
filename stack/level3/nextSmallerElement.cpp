vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);
  
  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}
