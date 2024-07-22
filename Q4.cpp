#include <iostream>
#include <string>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    
    std::string serialize(TreeNode* root) {
        if (!root) return "null";
        
        std::queue<TreeNode*> q;
        q.push(root);
        std::stringstream ss;
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }
        
        return ss.str();
    }

    
    TreeNode* deserialize(const std::string& data) {
        if (data == "null") return nullptr;

        std::stringstream ss(data);
        std::string item;
        std::getline(ss, item, ' ');
        TreeNode* root = new TreeNode(std::stoi(item));
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (std::getline(ss, item, ' ')) {
                if (item != "null") {
                    node->left = new TreeNode(std::stoi(item));
                    q.push(node->left);
                }
            }

            if (std::getline(ss, item, ' ')) {
                if (item != "null") {
                    node->right = new TreeNode(std::stoi(item));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        std::cout << "null" << std::endl;
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "null ";
        }
    }
    std::cout << std::endl;
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    std::string serialized = codec.serialize(root);
    std::cout << "Serialized: " << serialized << std::endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    std::cout << "Deserialized: ";
    printTree(deserialized);

    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
