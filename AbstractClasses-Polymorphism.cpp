class LRUCache:public Cache{
    public:
        LRUCache(int capacity){
            cp=capacity;
        }
        void set(int key,int value){
            if(mp.empty()){
                Node *temp=new Node(key,value);
                head=tail=temp;
                mp[key]=temp;
            }
            else{
                auto it=mp.find(key);
                if(it!=mp.end()){
                    it->second->value=value;
                    if(head==it->second)
                        return;
                    it->second->prev->next=it->second->next;
                    if(it->second==tail)
                        tail=tail->prev;
                    else
                        it->second->next->prev=it->second->prev;
                    it->second->next=head;
                    it->second->prev=NULL;
                    head->prev=it->second;
                    head=it->second;
                }
                else{
                    if(mp.size()>=cp){
                        tail->prev->next=tail->next;
                        Node *temp=tail;
                        tail=temp->prev;
                        mp.erase(temp->key);
                        delete(temp);
                    }
                    Node *temp=new Node(head->prev,head,key,value);
                    head->prev=temp;
                    head=temp;
                    mp[key]=temp;
                }
            }
        }
        int get(int key){
            auto it=mp.find(key);
            if(it==mp.end())
                return -1;
            return it->second->value;
        }
};
