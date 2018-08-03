
//uva122
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 300;
bool failed;
char s[maxn];
struct Node{
    bool have_value;
    int v;
    Node *left, *right;
    Node() : have_value(false), left(NULL), right(NULL) {
    };
};
Node *root;

Node* newnode(){
    return new Node();
}

void addnode(int v, char *s){
    int n = strlen(s);
    Node *u = root;
    for (int i = 0; i < n; i++){
        if (s[i] == 'L'){
            if (u->left == NULL)
                u->left = newnode();
            u = u->left;
        }
        else if (s[i] == 'R') {
            if (u->right == NULL)
                u->right = newnode();
            u = u->right;
        }
    }
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
}

void remove_tree(Node *u) {
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    free(u);
}

bool read_input() {
    failed = false;
    remove_tree(root);
    root = newnode();
    while (1) {
        if (scanf("%s", s) != 1)
            return false;
        if (!strcmp(s, "()"))
            break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',') + 1);
    }
    return true;
}

int n = 0;
vector<int> ans;
bool bfs() {
    queue<Node *> q;
    ans.clear();
    q.push(root);
    while (!q.empty()) {
        Node* u = q.front();
        q.pop();
        if (!u->have_value)
            return false;
        ans.push_back(u->v);
        n++;
        if (u->left != NULL)
            q.push(u->left);
        if (u->right != NULL)
            q.push(u->right);
    }
    return true;
}

int main() {
    while (read_input()) {
        if (!bfs())
            failed = 1;
        if (failed)
            printf("not complete\n");
        else {
            for (int i = 0; i < ans.size() - 1; i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[ans.size() - 1]);
        }
    }
    return 0;
}


