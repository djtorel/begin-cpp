.PHONY: clean All

All:
	@echo "----------Building project:[ 12-17-Section-Challenge - Debug ]----------"
	@cd "Section-12\12-17-Section-Challenge" && "$(MAKE)" -f  "12-17-Section-Challenge.mk"
clean:
	@echo "----------Cleaning project:[ 12-17-Section-Challenge - Debug ]----------"
	@cd "Section-12\12-17-Section-Challenge" && "$(MAKE)" -f  "12-17-Section-Challenge.mk" clean
