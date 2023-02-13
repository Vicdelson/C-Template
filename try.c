int FindMaxNodeKey();
struct node *search(int key);
void MoveToTail() {
    //Find maximum key first
    int max = FindMaxNodeKey();
    //Search the linked list and return the node with the maximum key
    struct node *start = search(max);
    
    //Finally, we can shift them one by one
    if(tail->val == start->val){
        return;
    } else{
        int tmp;
        struct node *current = start;
        int test = 0;
        while(1){
            if(current->next == tail){
                tmp = current->val;
                current->val = tail->val;
                tail->val = tmp;
                break;
            } else{
                tmp = current->val;
                current->val = current->next->val;
                current->next->val = tmp;
                current = current->next;
            }        
        }
    }
}



int FindMaxNodeKey(){
    int max = head->val;
    struct node *current = head->next;

    while(current != NULL){
        if(current->val > max){
            max = current->val;
        }
        current = current->next;
    }
    return max;
}

struct node *search(int key){
    struct node *current = head;
    while(current != NULL){
        if(current->val == key){
            return current;
        }
        current = current->next;
    }

    return NULL;
}