module "test1" {
  source = "./module"
  test = {
    key = {
      duration        = "1s"
      threshold_value = 0.66
      aligment_period = "2s"
      trigger_count   = 2
    }
  }
}

module "test2" {
  source = "./module"
  test = {
    key = {
      something       = "1s"
      something_again = 0.66
    }
  }
}

output "test1" {
  value = module.test1.out
}

output "test2" {
  value = module.test2.out
}
