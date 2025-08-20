#include <string>
#include <sstream>

class Codec {
public:
    /**
     * @brief Encodes a tree to a single string using pre-order traversal.
     */
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    /**
     * @brief Decodes your encoded data to a tree.
     */
    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserializeHelper(in);
    }

private:
    // Helper to recursively serialize the tree in pre-order.
    void serializeHelper(TreeNode* node, std::ostringstream& out) {
        if (!node) {
            out << "N ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    // Helper to recursively deserialize the string to a tree.
    TreeNode* deserializeHelper(std::istringstream& in) {
        std::string val;
        in >> val;

        if (val == "N") {
            return nullptr;
        }
        
        // This check handles an empty input string.
        if (in.fail()) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        
        return node;
    }
};