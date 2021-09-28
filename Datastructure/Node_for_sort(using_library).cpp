/* add operator into Node*/

struct Node{
    int l,r,id;

    bool operator<(const Node& rhs)const{
        return l<rhs.l;
    }
}
