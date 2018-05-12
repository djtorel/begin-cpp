.PHONY: clean All

All:
	@echo "----------Building project:[ 13-23-Section-Challenge - Debug ]----------"
	@cd "Section-13\13-23-Section-Challenge" && "$(MAKE)" -f  "13-23-Section-Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 13-23-Section-Challenge - Debug ]----------"
	@cd "Section-13\13-23-Section-Challenge" && "$(MAKE)" -f  "13-23-Section-Challenge.mk" clean
