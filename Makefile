.PHONY: clean All

All:
	@echo "----------Building project:[ 14-08-Section-Challenge-p2 - Debug ]----------"
	@cd "Section-14\14-08-Section-Challenge-p2" && "$(MAKE)" -f  "14-08-Section-Challenge-p2.mk"
clean:
	@echo "----------Cleaning project:[ 14-08-Section-Challenge-p2 - Debug ]----------"
	@cd "Section-14\14-08-Section-Challenge-p2" && "$(MAKE)" -f  "14-08-Section-Challenge-p2.mk" clean
