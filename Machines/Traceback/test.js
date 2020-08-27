router.post('/field', async (req, res) => {
  try {
    let users = await LawyerProfile.find({ practice_areas: req.body.field });
    console.log(users);
    res.json(users);
  } catch (err) {
    console.error(err.message);
    res.status(500).json({ msg: 'server error' });
  }
});