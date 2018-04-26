.PHONY: clean All

All:
	@echo "----------Building project:[ 10-07-Section-Challenge - Debug ]----------"
	@cd "Section-10\10-07-Section-Challenge" && "$(MAKE)" -f  "10-07-Section-Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 10-07-Section-Challenge - Debug ]----------"
	@cd "Section-10\10-07-Section-Challenge" && "$(MAKE)" -f  "10-07-Section-Challenge.mk" clean
