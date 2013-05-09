<?php

function devudo_attributes_devel($node) {
  return kpr($node->attributes, 1);
}