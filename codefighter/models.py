from django.db import models
from django.contrib.auth.models import User

class CustomUser(models.Model):
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    ratings = models.IntegerField()

    def __str__(self):
        return self.user.username

class TestCase(models.Model):
    input = models.FileField()
    output = models.FileField()

    def __str__(self):
        return os.path.basename(self.file.name)

levels = (('Easy','Easy'),('Medium','Medium'),('Hard','Hard'))

class Problem(models.Model):
    code = models.CharField(max_length=10)
    name = models.CharField(max_length=30)
    statement = models.TextField()
    memory_limit = models.IntegerField()
    time_limit = models.IntegerField()
    time_duration = models.IntegerField()
    hardness = models.CharField(max_length=7,choices = levels, default = 'Easy')
    author = models.ForeignKey(CustomUser,on_delete = models.CASCADE)
    testcase = models.ManyToManyField(TestCase)
    points = models.IntegerField()

    def __str__(self):
        return name

class Contest(models.Model):
    code = models.CharField(max_length=10)
    name = models.CharField(max_length=30)
    problem_list = models.ManyToManyField(Problem)
    start_time = models.TimeField()
    end_time = models.TimeField()
    user_list = models.ManyToManyField(CustomUser)

    def __str__(self):
        return name

verd = (('AC','AC'),('WA','WA'),('TLE','TLE'))

class Submission(models.Model):
    problem = models.ForeignKey(Problem,on_delete = models.CASCADE)
    contest = models.ForeignKey(Contest,on_delete = models.CASCADE)
    user = models.ForeignKey(CustomUser,on_delete = models.CASCADE)
    verdict = models.CharField(max_length=10, choices = verd, default = 'WA')

    def __str__(self):
        return self.user.user.name + ' ' + self.problem.name + ' ' + self.verdict

class Ranklist(models.Model):
    contest = models.ForeignKey(Contest,on_delete = models.CASCADE)

    def __str__(self):
        return self.contest.name

