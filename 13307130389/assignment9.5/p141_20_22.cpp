/*
Problem 20
        
        1.Dfs on the Huffman-Tree
        
              void Dfs( int k , int& code )
              {
                   if( isLeaf(k) )
                   {
                       table[ charOfLeaf ] = code ;
                       return ;
                   }
                   if( ch[k][0] != 0 ) Dfs( ch[k][0] , code<<1 ) ;
                   if( ch[k][1] != 0 ) Dfs( ch[k][1] , (code<<1)+1) ;
              }
        
        2.for each character in string S
              decode_of_s[i] = table[ S[i] ] ;

Problem 22

        Use left-child-right-brother mode can convert any tree to binary tree.
        
        How to re_convert?
        
        Next algorithm will do this.
        
             void reconvert( int root , int k )
             {
                  parent[k] = root ;
                  if( hasLeftChild(k) )
                      reconvert( k , leftChild(k) ) ;
                  if( hasRightChild(k) )
                      reconvert( root , rightChild(k) ) ;
             }

That's all.
Thanks for reading.

Author = xiaoguai0992 ;
id = 13307130389 ;
*/
