from scipy.stats import poisson
from numpy import random
import statsmodels.api as sm

x=random.rand(1000)*50
b=5
y=poisson.rvs(b*x)

gamma_model = sm.GLM(y,x, family=sm.families.Gamma())
gamma_results = gamma_model.fit()
gamma_results.summary()
z=zip(y,gamma_results.predict(x))
print z
