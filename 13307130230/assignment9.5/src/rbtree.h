class RBTREE
{
private:
    static const int size=100005;
    static const int oo=0x7fffffff;
    struct Node
    {
        int x,ch[2],fa,s;
        bool red;
        Node(){}
        Node(int u,int v)
        {
            s=1; x=u; fa=v;
            red=true;
            ch[0]=0; ch[1]=0;
        }
    } tree[size];
    int tot,root;

    inline int dir(int u)
    {
        return tree[tree[u].fa].ch[0]!=u;
    }

    void rotate(int u)
    {
        int d=dir(u);
        int fa=tree[u].fa;
        int gfa=tree[fa].fa;
        int son=tree[u].ch[1-d];
        tree[u].fa=gfa;
        tree[gfa].ch[dir(fa)]=u;
        tree[fa].fa=u;
        tree[u].ch[1-d]=fa;
        tree[son].fa=fa;
        tree[fa].ch[d]=son;
        tree[u].s=tree[fa].s;
        tree[fa].s=tree[tree[fa].ch[0]].s+tree[tree[fa].ch[1]].s+1;
        if (root==fa) root=u;
    }

    void add(int u)
    {
        int fa=tree[u].fa;
        if (!tree[fa].red) return;
        int gfa=tree[fa].fa;
        int unc=tree[gfa].ch[1-dir(fa)];
        if (tree[unc].red)
        {
            tree[gfa].red=true;
            tree[fa].red=false;
            tree[unc].red=false;
            add(gfa);
        } else
        {
            if (dir(u)==dir(fa))
            {
                rotate(fa);
                tree[gfa].red=true;
                tree[fa].red=false;
            }
            else
            {
                rotate(u);
                rotate(u);
                tree[gfa].red=true;
                tree[u].red=false;
            }
        }
        tree[root].red=false;
    }

    void add_ready(int u,int v,int d)
    {
        tree[++tot]=Node(v,u);
        tree[u].ch[d]=tot;
        for (int tp=u;tp;tp=tree[tp].fa) tree[tp].s++;
        add(tot);
    }

    void Insert(int u,int v)
    {
        if (v<=tree[u].x)
        {
            if (tree[u].ch[0]==0) add_ready(u,v,0);
            else Insert(tree[u].ch[0],v);
        } else
        {
            if (tree[u].ch[1]==0) add_ready(u,v,1);
            else Insert(tree[u].ch[1],v);
        }
    }

    void del(int u)
    {
        if (tree[u].red)
        {
            tree[u].red=false;
            return;
        }
        int fa=tree[u].fa;
        int bro=tree[fa].ch[1-dir(u)];
        if (tree[bro].red)
        {
            rotate(bro);
            tree[fa].red=true;
            tree[bro].red=false;
            del(u);
        } else
        if (tree[tree[bro].ch[0]].red||tree[tree[bro].ch[1]].red)
        {
            int cus=tree[tree[bro].ch[0]].red?tree[bro].ch[0]:tree[bro].ch[1];
            if (dir(cus)==dir(bro))
            {
                rotate(bro);
                tree[bro].red=tree[fa].red;
                tree[fa].red=false;
                tree[cus].red=false;
            } else
            {
                rotate(cus);
                rotate(cus);
                tree[cus].red=tree[fa].red;
                tree[fa].red=false;
            }
        } else
        {
            tree[bro].red=true;
            del(fa);
        }
    }

    void del_ready(int u)
    {
        for (int tp=u;tp;tp=tree[tp].fa) tree[tp].s--;
        tree[u].s=0;
        if (tree[u].red) tree[tree[u].fa].ch[dir(u)]=0;
        else
        {
            int son=tree[u].ch[1]!=0?tree[u].ch[1]:tree[u].ch[0];
            tree[tree[u].fa].ch[dir(u)]=son;
            tree[son].fa=tree[u].fa;
            if (root==u) root=son;
            del(son);
        }
    }

    void Erase(int u,int v)
    {
        if (tree[u].x==v)
        {
            if (tree[u].ch[0]==0) del_ready(u);
            else
            {
                int pre=tree[u].ch[0];
                while (tree[pre].ch[1]) pre=tree[pre].ch[1];
                swap(tree[u].x,tree[pre].x);
                del_ready(pre);
            }
            return;
        }
        if (v<=tree[u].x) Erase(tree[u].ch[0],v);
        else Erase(tree[u].ch[1],v);
    }

    int Find(int u,int v)
    {
        if (tree[tree[u].ch[0]].s+1==v) return tree[u].x;
        if (v<=tree[tree[u].ch[0]].s) return Find(tree[u].ch[0],v);
        return Find(tree[u].ch[1],v-tree[tree[u].ch[0]].s-1);
    }

public:
    RBTREE()
    {
        root=0;
        tot=0;
        tree[0]=Node(oo,0);
        tree[0].red=false;
        tree[0].s=0;
    }

    void insert(int u)
    {
        if (root==0)
        {
            tree[++tot]=Node(u,0);
            tree[tot].red=false;
            root=tot;
        } else
        Insert(root,u);
    }

    void erase(int u)
    {
        Erase(root,u);
    }

    int Find_kth(int u)
    {
        return Find(root,u);
    }
};
