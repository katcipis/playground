variable "test" {
  type = map(object({
    duration                       = optional(string, "300s")
    threshold_value                = optional(number, 0.85)
    alignment_period               = optional(string, "120s")
    trigger_count                  = optional(number, 1)
  }))
}
