#pragma once

#include "CalculatorBase.h"

class SimpleCalculator : public CalculatorBase
{
private:
	int evaluateNode() const;
	int evaluateExpression() const;
	virtual void perform();
public:
	SimpleCalculator(TokenizerBase&,std::ostream&,std::ostream&);
};

