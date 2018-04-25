.PHONY: clean All

All:
	@echo "----------Building project:[ 09-15-Section-Challenge - Debug ]----------"
	@cd "Section-09\09-15-Section-Challenge" && "$(MAKE)" -f  "09-15-Section-Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 09-15-Section-Challenge - Debug ]----------"
	@cd "Section-09\09-15-Section-Challenge" && "$(MAKE)" -f  "09-15-Section-Challenge.mk" clean
