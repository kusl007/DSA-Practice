int toSumTree(node *Node) 
{ 
    // Base case 
    if(Node == NULL) 
    return 0; 
 
    // Store the old value 
    int data = Node->data; 
 
    int left_sum = toSumTree(Node->left); 
    int right_sum = toSumTree(Node->right);
    Node->data = data+left_sum+right_sum;
    return Node->data ; 
} 