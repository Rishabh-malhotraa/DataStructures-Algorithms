-- High-Level Requirements
-- User Management:

-- Users can sign up with an email and password.
-- A user can have multiple addresses (billing, shipping, etc.).
-- Product Catalog:

-- Each product has a name, description, price, and belongs to one or more categories.
-- A product has stock levels (inventory) that need to be tracked.
-- Shopping Cart:

-- A user can add multiple products to their cart, with specified quantities.
-- The user can update or remove items from their cart.
-- Order Processing:

-- When a user checks out, an order is created.
-- Each order has one or more order items (product + quantity + current price).
-- An order tracks its status (e.g., pending, paid, shipped, delivered, canceled).
-- An order can have shipping details (address, shipping method, tracking number).
-- Payment:

-- Each order has an associated payment record (method, status, transaction ID).
-- Payment can be pending or completed, and multiple payment methods might be supported (credit card, PayPal, etc.).
-- Reviews (Optional advanced feature):

-- A user can write a review for a product if they’ve purchased it.
-- Each review can have a rating (1–5) and a comment.
-- Reporting and Analytics (Optional advanced feature):

-- Admins might want to see total sales, revenue by product category, etc.


CREATE TABLE user (
  user_id INT NOT NULL PRIMARY KEY,
  first_name VARCHAR(50) NOT NULL,
  last_name VARCHAR(50),
)

CREATE TABLE address (
  address_id INT NOT NULL PRIMARY KEY,
  address VARCHAR(255) NOT NULL,
  FOREIGN KEY (user_id) REFERENCES user(user_id)
);

CREATE TABLE products (
  product_id INT PRIMARY KEY AUTO_INCREMENT,
  product_name VARCHAR(255) NOT NULL,
  price DECIMAL(10, 2) NOT NULL,
  description TEXT,
  quantity INT
);

CREATE TABLE categories (
  category_id PRIMARY KEY AUTO_INCREMENT,
  category_name VARCHAR(255) NOT NULL
);

CREATE TABLE product_categories(
  category_id INT NOT NULL,
  product_id INT NOT NULL,
  FOREIGN KEY (category_id) REFERENCES products(product_id) ON DELETE CASCADE,
  FOREIGN KEY (product_id) REFERENCES categories(category_id) ON DELETE CASCADE
)

CREATE TABLE cart {
  cart_id PRIMARY KEY AUTO_INCREMENT NOT NULL;
  product_id INT NOT NULL;
  FOREIGN KEY (product_id) REFERENCES product(product_id) ON DELETE CASCADE;
  quantity INT;
}

CREATE TABLE ORDER {
  cart_id PRIMARY KEY AUTO_INCREMENT NOT NULL;
  product_id INT NOT NULL;
  FOREIGN KEY (product_id) REFERENCES product(product_id) ON DELETE CASCADE;
  quantity INT;
}