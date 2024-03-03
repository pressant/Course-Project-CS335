class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert_recursively(self.root, data)

    def _insert_recursively(self, current_node, data):
        if data < current_node.data:
            if current_node.left is None:
                current_node.left = Node(data)
            else:
                self._insert_recursively(current_node.left, data)
        elif data > current_node.data:
            if current_node.right is None:
                current_node.right = Node(data)
            else:
                self._insert_recursively(current_node.right, data)
        else:
            print("Duplicate values not allowed")

    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(node.data, end=' ')
            self.inorder_traversal(node.right)

    def preorder_traversal(self, node):
        if node:
            print(node.data, end=' ')
            self.preorder_traversal(node.left)
            self.preorder_traversal(node.right)

    def postorder_traversal(self, node):
        if node:
            self.postorder_traversal(node.left)
            self.postorder_traversal(node.right)
            print(node.data, end=' ')

    def search(self, key):
        return self._search_recursively(self.root, key)

    def _search_recursively(self, node, key):
        if node is None or node.data == key:
            return node
        if key < node.data:
            return self._search_recursively(node.left, key)
        return self._search_recursively(node.right, key)

    def delete(self, key):
        self.root = self._delete_recursively(self.root, key)

    def _delete_recursively(self, root, key):
        if root is None:
            return root

        if key < root.data:
            root.left = self._delete_recursively(root.left, key)
        elif key > root.data:
            root.right = self._delete_recursively(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            root.data = self._get_min_value(root.right)
            root.right = self._delete_recursively(root.right, root.data)

        return root

    def _get_min_value(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current.data

if __name__ == "__main__":
    binary_tree = BinaryTree()
    elements = [7, 4, 10, 2, 6, 8, 12, 1, 3, 5, 9, 11, 13]
    for element in elements:
        binary_tree.insert(element)

    print("Inorder Traversal of Binary Tree:")
    binary_tree.inorder_traversal(binary_tree.root)
    print("\nPreorder Traversal of Binary Tree:")
    binary_tree.preorder_traversal(binary_tree.root)
    print("\nPostorder Traversal of Binary Tree:")
    binary_tree.postorder_traversal(binary_tree.root)

    print("\nSearching for element 10:", binary_tree.search(10))
    print("Searching for element 14:", binary_tree.search(14))

    binary_tree.delete(7)
    print("\nInorder Traversal after deleting element 7:")
    binary_tree.inorder_traversal(binary_tree.root)

