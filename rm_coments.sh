#!/bin/bash
find . -name "*.[ch]" | xargs -I{} rm_comments {}

