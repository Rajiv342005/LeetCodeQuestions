class Solution {
public:
    void RedTraversal(int red,int blue,int &length){
        bool b = true;
        int index=1;
        while(true){
            if(b){
            if(blue>=index){
                blue-=index;
                index++;
                length++;
            }
            else return;
            }
            else{
                if(red>=index){
                    red-=index;
                    index++;
                    length++;
                }
                else return;
            }
            b = !b;
        }
    }
    void BlueTraversal(int red,int blue,int &length){
        bool b = false;
        int index=1;
        while(true){
            if(b){
            if(blue>=index){
                blue-=index;
                index++;
                length++;
            }
            else return;
            }
            else{
                if(red>=index){
                    red-=index;
                    index++;
                    length++;
                }
                else return;
            }
            b = !b;
        }
    }
    int maxHeightOfTriangle(int red, int blue) {
        int length=0;
        int length2=0;
        RedTraversal(red,blue,length);
        BlueTraversal(red,blue,length2);
        return max(length,length2);
    }
};