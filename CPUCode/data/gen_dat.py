from scipy.stats import poisson
from numpy import random,exp
import statsmodels.api as sm
from scipy.spatial import distance

x=random.rand(5000)*10
b=.2
y=poisson.rvs(exp(b*x))

print x

gamma_model = sm.GLM(y,x, family=sm.families.Poisson())
gamma_results = gamma_model.fit()
print zip(y,gamma_results.predict(x))

print gamma_results.summary()

print distance.euclidean(y,gamma_results.predict(x))
with open('poisson.x','w') as f:
    f.writelines("%.4f\n" % xi for xi in x)
with open('poisson.y','w') as f:
    f.writelines("%d\n" % yi for yi in y)
