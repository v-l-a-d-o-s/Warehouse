import integration_test_base

class ProductIntegrationTest(integration_test_base.BaseTestCase):

    def test_create_product(self):
       product = self.app.create_product(name="Апельсин", price=40.0, quantity=5) 
       product = self.app.get_product(product.id)   
       self.assertEqual(product.name, "Апельсин")