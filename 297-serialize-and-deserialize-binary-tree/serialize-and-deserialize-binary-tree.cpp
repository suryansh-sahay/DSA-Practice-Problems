

class Codec {
public:
    /**
     * @brief Encodes a tree to a single string using pre-order traversal.
     * @param root The root of the binary tree.
     * @return A string representation of the tree.
     */
    std::string serialize(TreeNode* root) {
        std::ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    /**
     * @brief Decodes your encoded data to a tree.
     * @param data The string representation of the tree.
     * @return The root of the reconstructed binary tree.
     */
    TreeNode* deserialize(std::string data) {
        std::istringstream in(data);
        return deserializeHelper(in);
    }

private:
    // Helper function to perform recursive pre-order serialization.
    void serializeHelper(TreeNode* node, std::ostringstream& out) {
        // Base case: If the node is null, write the null marker 'N'.
        if (node == nullptr) {
            out << "N ";
            return;
        }
        
        // Pre-order: Visit Root, then Left, then Right.
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    // Helper function to perform recursive pre-order deserialization.
    TreeNode* deserializeHelper(std::istringstream& in) {
        std::string val;
        // Read the next space-separated token from the stream.
        in >> val;

        // Base case: If the token is the null marker, this branch is null.
        if (val == "N") {
            return nullptr;
        }
        
        // Handle empty input string case where the stream read might fail.
        if (in.fail()) {
            return nullptr;
        }

        // Pre-order: Create the Root node first.
        TreeNode* node = new TreeNode(std::stoi(val));
        
        // Recursively build the left and right subtrees.
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        
        return node;
    }
};
