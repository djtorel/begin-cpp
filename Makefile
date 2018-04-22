.PHONY: clean All

All:
	@echo "----------Building project:[ 04-03-First-Program - Debug ]----------"
	@cd "Section-04\04-01-First-Program" && "$(MAKE)" -f  "04-03-First-Program.mk"
clean:
	@echo "----------Cleaning project:[ 04-03-First-Program - Debug ]----------"
	@cd "Section-04\04-01-First-Program" && "$(MAKE)" -f  "04-03-First-Program.mk" clean
